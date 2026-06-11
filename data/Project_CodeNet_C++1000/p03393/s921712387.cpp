#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <stack>
#include <queue>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    string S, T;
    ll al[26], i, j, k=-1, judge=0;
    char ch, ch2;

    cin >> S;

    for(i=0; i<26; i++){
        al[i] = 0;
    }

    for(i=0; i<S.size(); i++){
        al[S[i]-'a']++;
    }

    i = 0;
    while(al[i]==1){
        i++;
        if(al[i]==0){
            j = i;
            break;
        }
        else if(i==25){
            judge = 1;
            break;
        }
    }

    if(judge==1){ // 26文字のとき
        for(i=25; i>=1; i--){
            if(S[i-1] < S[i]){
                k = i-1;
                break;
            }
        }

        if(k==-1) cout << -1 << endl;
        else{
            T = S.substr(0, k);
            ch = S[k];
            ch2 = ch;
            for(i=k+1; i<=25; i++){
                if(ch==ch2 && S[i]>ch){
                    ch = S[i];
                }
                else if(ch!=ch2 && ch2<S[i] && S[i]<ch){
                    ch = S[i];
                }
            }
            cout << T << ch << endl;
        }
    }

    else{ // 25文字以下のとき
        ch = 'a'+j;

        cout << S << ch << endl;
    }

    return 0;
}