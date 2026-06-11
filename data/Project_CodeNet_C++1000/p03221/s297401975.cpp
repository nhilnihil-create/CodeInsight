#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll F(ll A){
ll countA = 0;

while(A > 0){
A /=10;
countA++;}
return countA;
}

int main() {
ll N, M;cin >> N >> M;
vector<pair<ll, pair<ll, ll>>> V(M);
vector<pair<ll, ll>> A(M);
map<ll, ll> P;

rep(i, 0, M){

    cin >> V[i].second.first >> V[i].first ;

    V[i].second.second = i + 1;

}

sort(ALL(V));
  
  //for(auto v : V )
    //cout << v.first << " " << v.second.first << " " << v.second.second << endl;

rep(i, 0 , M){

    P[V[i].second.first]++;

    V[i].first = P[V[i].second.first];
 
}
  
 //for(auto v : V )
    //cout << v.first << " " << v.second.first << " " << v.second.second << endl;

rep(i, 0, M){

    A[V[i].second.second - 1].first = V[i].second.first;
  
    A[V[i].second.second - 1].second = V[i].first;

}

for(auto a : A ){

    rep(i, 0, 6 - F(a.first)){

        cout << 0;

    }

    cout << a.first;

    rep(i, 0, 6 - F(a.second)){

        cout << 0;

    }

    cout << a.second << endl;
    
}

}