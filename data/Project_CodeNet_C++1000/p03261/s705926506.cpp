#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s.at(i);
    }
    int i=0;
    while(i<n){
        for(int j=i+1; j<n; j++){
         if(s.at(i) == s.at(j)){
             cout << "No" << endl;
             return 0;
         }
        }
        i += 1;
    }
    for(int k=1; k<n; k++){
        if(s.at(k).at(0) != s.at(k-1).at((int)s.at(k-1).size()-1)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}

