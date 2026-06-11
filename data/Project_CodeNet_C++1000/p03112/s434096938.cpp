#include<bits/stdc++.h>
using namespace std;

long long int a,b,q,i;
vector<long long int> s,t,x;


int main(){
    cin>>a>>b>>q;
    s.resize(a+2);
    t.resize(b+2);
    x.resize(q);
    for(i=1;i<=a;i++){
        cin>>s[i];
    }
    for(i=1;i<=b;i++){
        cin>>t[i];
    }
    for(i=0;i<q;i++){
        cin>>x[i];
    }
    s[0]=t[0]=-500000000000;//両端に番兵
    s[a+1]=t[b+1]=500000000000;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    vector<long long int> ans(q);
    long long int key1,key2;
    vector<long long int>::iterator position;
    
    for(i=0;i<q;i++){//二分探索
        position=lower_bound(s.begin(),s.end(),x[i]);
        key1=distance(s.begin(),position);//xより大きい最小値の場所(sにおいて)

        position=lower_bound(t.begin(),t.end(),x[i]);
        key2=distance(t.begin(),position);//xより大きい最小値の場所(tにおいて)

        ans[i]=500000000000;
        
        //最小値を探す
        ans[i]=min(ans[i],max(s[key1]-x[i],t[key2]-x[i]));
        ans[i]=min(ans[i],max(x[i]-s[key1-1],x[i]-t[key2-1]));
        ans[i]=min(ans[i],s[key1]+x[i]-2*t[key2-1]);
        ans[i]=min(ans[i],2*s[key1]-x[i]-t[key2-1]);
        ans[i]=min(ans[i],t[key2]+x[i]-2*s[key1-1]);
        ans[i]=min(ans[i],2*t[key2]-x[i]-s[key1-1]);
    }
    for(i=0;i<q;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}