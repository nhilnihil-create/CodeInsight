#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(string s,int n){
    
}


int main(){
    string s;
    cin >> s;
    int n = s.size();
    int zero = 0, one = 0;
    for(int i=0;i<n;i++){
        if(s.at(i) == '1') one++;
        else zero ++ ;
    }
    int delta = abs(one - zero);
    cout << n - delta << endl;

}