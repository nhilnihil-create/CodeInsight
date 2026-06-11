#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
//long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;
/*
bool comp(P a, P b){
    if(a.first < b.first){
        return true;
    }else{
        return a.second > b.second;
    }
}*/

int main(){
    int N;
    cin >> N;
    vector<P> R(N),B(N);
    rep(i,N){
        cin >> R[i].first >> R[i].second;
    }
    rep(i,N){
        cin >> B[i].first >> B[i].second;
    }
    sort(R.begin(),R.end(),greater<pair<int,int>>());
    sort(B.begin(),B.end());
    int cnt = 0;
    rep(i,N){
        auto iter = upper_bound(B.begin(), B.end(), R[i]);
        if(iter != B.end()){
            //if(B[ind].first > R[i].first && B[ind].second > R[i].second){
            int m = 1000000;
            auto iter_rec = iter;
            while(iter != B.end()){
                //cout << "a"<<endl;
                if((*iter).second <= R[i].second){iter++; continue;}
                int tmp = min(m, (*iter).second);
                if(tmp != m){
                    iter_rec = iter;
                    m = tmp;
                }
                iter++;
            }
            //cout << (*iter).second << " " << (*iter_rec).second << endl;
            if(m > R[i].second && m != 1000000){
                B.erase(iter_rec);
                cnt++;
            }
            
            //B.erase(iter);
            //cnt++;
            //B[ind] = make_pair(-1,-1);
            //}
        }
    }
    cout << cnt << endl;
    /*rep(i,N){
        cout << R[i].first <<" " <<R[i].second<<endl;
    }*/
}
