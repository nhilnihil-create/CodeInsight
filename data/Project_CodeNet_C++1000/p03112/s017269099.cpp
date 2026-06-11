#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    long A, B, Q;
    cin>>A>>B>>Q;
    long s[A], t[B], x[Q];
    for(long i=0;i<A;++i){
        cin>>s[i];
    }
    for(long i=0;i<B;++i){
        cin>>t[i];
    }
    for(long i=0;i<Q;++i){
        cin>>x[i];
    }
    vector<long>xarr;
    for(long i=0;i<Q;++i){
        xarr.push_back(x[i]);
    }
    sort(xarr.begin(), xarr.end());
    map<long, long> ans;
    long sh=0, te=0;
    long tmpans1, tmpans2, tmpans3, tmpans4;
    for(long now=0;now<Q;++now){
        while(s[sh]<xarr[now] & sh<A-1){
            sh++;
        }
        while(t[te]<xarr[now] & te<B-1){
            te++;
        }
        if(sh>0 & te>0){
            tmpans1 = abs(xarr[now] - s[sh-1]);
            if(abs(s[sh-1] - t[te]) < abs(s[sh-1] - t[te-1])) tmpans1 += abs(s[sh-1] - t[te]);
            else tmpans1 += abs(s[sh-1] - t[te-1]);

            tmpans2 = abs(xarr[now] - s[sh]);
            if(abs(s[sh] - t[te]) < abs(s[sh] - t[te-1])) tmpans2 += abs(s[sh] - t[te]);
            else tmpans2 += abs(s[sh] - t[te-1]);

            tmpans3 = abs(xarr[now] - t[te-1]);
            if(abs(t[te-1] - s[sh]) < abs(t[te-1] - s[sh-1])) tmpans3 += abs(t[te-1] - s[sh]);
            else tmpans3 += abs(t[te-1] - s[sh-1]);

            tmpans4 = abs(xarr[now] - t[te]);
            if(abs(t[te] - s[sh]) < abs(t[te] - s[sh-1])) tmpans4 += abs(t[te] - s[sh]);
            else tmpans4 += abs(t[te] - s[sh-1]);
            ans[xarr[now]] = min(tmpans1, min(tmpans2, min(tmpans3, tmpans4)));
            //cout<<xarr[now]<<" "<<tmpans1<<" "<<tmpans2<<" "<<tmpans3<<" "<<tmpans4<<" "<<sh<<" "<<te<<endl;
        }
        else if(sh==0 & te>0){
            tmpans1 = abs(xarr[now] - s[sh]);
            if(abs(s[sh] - t[te]) < abs(s[sh] - t[te-1])) tmpans1 += abs(s[sh] - t[te]);
            else tmpans1 += abs(s[sh] - t[te-1]);

            tmpans2 = abs(xarr[now] - t[te]);
            tmpans2 += abs(t[te] - s[sh]);
            tmpans3 = abs(xarr[now] - t[te-1]);
            tmpans3 += abs(t[te-1] - s[sh]);
            ans[xarr[now]] = min(tmpans1, min(tmpans2, tmpans3));
        }
        else if(sh>0 & te==0){
            tmpans1 = abs(xarr[now] - t[te]);
            if(abs(t[te] - s[sh]) < abs(t[te] - s[sh-1])) tmpans1 += abs(t[te] - s[sh]);
            else tmpans1 += abs(t[te] - s[sh-1]);

            tmpans2 = abs(xarr[now] - s[sh]);
            tmpans2 += abs(s[sh] - t[te]);
            tmpans3 = abs(xarr[now] - s[sh-1]);
            tmpans3 += abs(s[sh-1] - t[te]);
            ans[xarr[now]] = min(tmpans1, min(tmpans2, tmpans3));
        }
        else {
            tmpans1 = abs(xarr[now] - s[sh]) + abs(s[sh] - t[te]);
            tmpans2 = abs(xarr[now] - t[te]) + abs(t[te] - s[sh]);
            ans[xarr[now]] = min(tmpans1, tmpans2);
        }
    }
    for(long i=0;i<Q;++i){
        cout<<ans[x[i]]<<endl;
    }
}
