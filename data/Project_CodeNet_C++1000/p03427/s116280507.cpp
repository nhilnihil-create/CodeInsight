#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;   cin >> s;
    int sum=0;
    for(int i=0; i<s.size(); i++)
        sum += s[i]-'0';
    sum = max(sum, (s[0]-'0'-1)+9*(int)(s.size()-1));
    cout << sum << endl;
}
    
