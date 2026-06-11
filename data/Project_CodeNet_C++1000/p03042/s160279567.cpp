#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int toInt(string s){
    stringstream geek (s);
    int x = 0;
    geek >> x;
    return x;
}
int main(){
    Hello
    string s;
    cin >> s;
    string s1 = "";
    s1 += s[0];
    s1 += s[1];
    string s2 = "";
    s2 += s[2];
    s2 += s[3];
    int firstNumb = toInt(s1), secondNumb = toInt(s2);
    if(firstNumb >= 1 && firstNumb <= 12 && secondNumb >= 1 && secondNumb <= 12)
        cout << "AMBIGUOUS";
    else if(firstNumb >= 1 && firstNumb <= 12)
        cout << "MMYY";
    else if(secondNumb > 0 && secondNumb <= 12)
        cout << "YYMM";
    else cout << "NA";
    return 0;
}
