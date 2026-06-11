#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a=0;
    int b=0;
    int c=0;
    for(int i=0;i<3;i++){
        if(s[i]=='a')a++;
        else if(s[i]=='b')b++;
        else c++;
    }
    if(a==0 || b==0 || c==0)cout << "No" << endl;
    else cout << "Yes" << endl;
}