#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string s;
    cin >> s;
    int N=s.size();

    if(s[0]=='0' || s[N-1]=='1'){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<N/2; i++){
        if(s[i]!=s[N-2-i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int j=1;
    for(int i=0; i<(int)s.size()-1; i++){
        cout << j << ' ' << i+2 << '\n';
        if(s[i]=='1'){    
            j=i+2;
        }
    }
}