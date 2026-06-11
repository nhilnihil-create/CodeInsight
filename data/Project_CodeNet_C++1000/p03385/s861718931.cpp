#include <bits/stdc++.h>
using namespace std;

int a=0;
int b=0;
int c=0;

void count(string s, int n){
    if(s.at(n) == 'a') a++;
    else if(s.at(n) == 'b') b++;
    else c++;
}

int main(){
    string s;
    cin >> s;
    count(s, 0);
    count(s,1);
    count(s,2);

    if(a==1 && b == 1 && c==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}