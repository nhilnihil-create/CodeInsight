#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long int ans = 0;
    queue<int> q;

    for(int i=0; i<(int)s.length(); i++){
        if(s[i] == 'A') q.push(0);
        else if(i+1<(int)s.length() && s[i] == 'B' && s[i+1] == 'C'){ q.push(1); i += 1; }
        else{
            int a = 0;
            while(q.empty() == false){
                if(q.front() == 0) a += 1;
                if(q.front() == 1) ans += a;
                q.pop();
            }
        }
    }
    int a = 0;
    while(q.empty() == false){
        //cout << q.front() << " ";
        if(q.front() == 0) a += 1;
        if(q.front() == 1) ans += a;
        q.pop();
    }
    cout << ans << endl;
    return 0;
}