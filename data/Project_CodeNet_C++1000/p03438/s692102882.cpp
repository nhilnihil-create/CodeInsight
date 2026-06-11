#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N),b(N),c(N);
    ll sum_a=0, sum_b=0, sum=0;
    rep(i,N){
        cin >> a[i];
        sum_a += a[i];
    }
    rep(i,N){
        cin >> b[i];
        sum_b += b[i];
    }
    sum = sum_b - sum_a;
    ll cnt1 = 0, cnt2=0;
    rep(i,N){
        if(b[i]-a[i] > 0){
            cnt1 += ((b[i] - a[i] + 1)/2);
        }else if(b[i] - a[i] < 0){
            cnt2 += (a[i] - b[i]);
        }
    }
    if(cnt1 <= sum && cnt2<=sum){
        cout << "Yes" << endl;
    }else{
        cout << "No" <<endl;
    }
    
    /*
    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N){
        c[i] = b[i] - a[i];
        que.push(c[i]);
    }
    while(que.top() < 0){


    }
    
    sort(c.begin(),c.end());
    bool flag = true;
    while(flag){
        flag = false;
        rep(i,N){
            if(c[i] == 0)continue;
            flag = true;
            if(c[i] < 0){
                c[i]++;
                c[N-1] -=2;
                if(c[N-1] < 0 ){
                    cout << "No" << endl;
                    return 0;
                }
            }else{
//                c[N-1] -= 2;
 //               if(c[N-1] < 0){
                    cout << "Yes" << endl;
                    return 0;
 //               }
            }
            i = -1;
            sort(c.begin(),c.end());
        }
    }
    //priority_queue<ll,vector<ll>,greater<ll>> quea;
    cout << "Yes" << endl;*/
}
/*
-1 0 4
0 0 2


0 0 
99 -98

98 0
99 -49

98 40
99 -29

*/