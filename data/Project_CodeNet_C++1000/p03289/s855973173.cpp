#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const int inf =INT_MAX;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] != 'A'){
        cout << "WA" << "\n";
        return 0;
    }
    
    int seenC = 0;
    for(int i = 2; i < n-1; i++)
        if(s.at(i) == 'C')
            seenC++;
    
    if(seenC != 1){
        cout << "WA" << "\n";
        return 0;
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != 'A' && s[i] != 'C' && !islower(s[i])){
            cout << "WA" << "\n";
            return 0;
        }
    }

    cout << "AC" << "\n";
    return 0;
}