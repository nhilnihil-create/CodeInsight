#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<char> S(N);
    for (int i = 0; i < N; i++){
        cin >> S.at(i);
    }
    vector<int> E(N,0);
    vector<int> W(N,0);
    for (int i = 0; i < N ; i++){
        if (i != N-1){
            W.at(i+1)=W.at(i);
            if(S.at(i)=='E') E.at(i)++;
            else W.at(i+1)++;
            E.at(i+1)=E.at(i);
        }
        else{
            if(S.at(i)=='E') E.at(i)++;
        }
    }
   
    int ans;
    int mans = N;
    for (int i = 0; i < N; i++){
        ans = W.at(i) + (E.at(N-1) - E.at(i));
        
        if (mans > ans) mans = ans;
    }
    
    cout << mans << endl;
}
