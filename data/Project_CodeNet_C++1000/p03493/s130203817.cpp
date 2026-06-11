#include<bits/stdc++.h>
using namespace std;

int main(){
    int s1;
    cin >> s1;
    int count = 0;
    if(s1 / 100 == 1)count++;
    if((s1 / 10) % 10 == 1)count++;
    if(s1 % 10 == 1)count++;
    cout << count << endl;
}