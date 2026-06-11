#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long num;
    vector<char> list;
    cin >> num;
    string b = to_string(num), c;
    for (int i=0; i<3; i++) {
        char a = b[i];
        c=a;
        list.push_back(stoll(c));}
    if (list[1]<list[0]) {cout << list[0]*100 + list[0]*10 + list[0];}
    else if (list[1]>=list[0]) {
        if (list[2]>list[0]) {cout << (list[0]+1)*100 + (list[0]+1)*10 + (list[0]+1);}
        else if (list[1]>list[0]) {cout << (list[0]+1)*100 + (list[0]+1)*10 + (list[0]+1);}
        else if (list[2]<list[0]) {cout << list[0]*100 + list[0]*10 + list[0];}
        else if (list[1]==list[0] && list[2]==list[0]) {cout << list[0]*100 + list[0]*10 + list[0];}}}