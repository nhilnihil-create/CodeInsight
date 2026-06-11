#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    int m = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            bool no = false;
            for(int t=i;t<=j;t++) if(!(s[t]=='A'||s[t]=='C'||s[t]=='G'||s[t]=='T')) no = true;
            if(no) break;
            m = max(m, j-i+1);
        }
    }

    cout << m << endl;
}
