#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 0;cin >> N;
queue<ll> Q;
vector<ll> V;

Q.push(3);Q.push(5);Q.push(7);

ll q = 0;

while(1){

    q = Q.front();
  
    if(q > N)break;
    
    Q.pop();

    Q.push(10*q + 3);Q.push(10*q + 5);Q.push(10*q + 7);

    V.push_back(q);

}

rep(i, 0, V.size()){

    string s = to_string(V[i]);

    bool C = 0, D = 0, E = 0;

    rep(j, 0, s.size()){

        if(s[j] == '3')C = 1;

        if(s[j] == '5')D = 1;

        if(s[j] == '7')E = 1;

    }

    if(C && D && E)Ans++;

}

cout << Ans;

}