#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int a,b;
    a=0;b=0;
    for(int i=0; i<s.length(); i++){
        if(i%2==0){
            if(s.at(i) == '0') b++;
            else a++;
        }
        else{
            if(s.at(i) == '0') a++;
            else b++;
        }
    }
    cout << min(a,b) << endl;
}