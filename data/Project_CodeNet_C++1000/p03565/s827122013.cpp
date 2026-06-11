#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
string S, T;cin >> S >> T;

vector<string> Ans;

rep(i, 0, S.size()- T.size() + 1){

    bool C = 1;

    rep(j, 0, T.size()){

        if(S[i + j] != '?' && S[i + j] != T[j]){C = 0;break;}

    }

    if(C){

        string N = S;

        rep(j, 0, T.size())N[i + j] = T[j];

        rep(j, 0, N.size()){

            if(N[j] == '?')N[j] = 'a';

        }

        Ans.push_back(N);

    }

}

sort(ALL(Ans));

if(Ans.empty())cout << "UNRESTORABLE";

else cout << Ans[0];
}