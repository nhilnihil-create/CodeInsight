#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long a,b,num,fin=1;
    cin >> num;
    deque<long long> list;
    for (long long i=0; i<num; i++) {cin >> a; list.push_back(a);}
    sort(list.begin(),list.end());
    a=list[0];
    for (long long i=1; i<num; i++) {
        b=list[i]; 
        if (a==b){}
        else {fin++;}
        a=b;}
    cout << fin;}