#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, M, Ans = 0;cin >> N >> M;
vector<ll> a(N);
map<ll, ll> P;

rep(i, 0, N){

    cin >> a[i];

    Ans += a[i];

    P[a[i]]++;

}

rep(i, 0, M){

    ll b, c;cin >> b >> c;

    for(auto p : P ){
    
        if(p.first >= c)break;

        if(b <= p.second){

            Ans += b*c - p.first*b;P[c] += b;
          
            P[p.first] -= b;
                    
            b = 0;          

            if(p.second == 0)P.erase(p.first);break;

        }

        else{

            Ans += p.second*c - p.first*p.second;
          
            P[c] += p.second;
          
            b -= p.second;
          
            P.erase(p.first);
           
        }

    }
  
  //for(auto p : P )cout << p.first << " " << p.second << endl;

}
cout << Ans;
}