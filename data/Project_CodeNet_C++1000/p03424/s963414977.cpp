#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;
    string s;
    bool Y = false;
    rep(i, N){
        s = "";
        cin >> s;
        
        if (s == "Y")
        {
            Y = true;
        }
        
        
    }

    if (Y){
        cout << "Four" << endl;
    }
    else
    {
        cout << "Three" << endl;
    }
    
}