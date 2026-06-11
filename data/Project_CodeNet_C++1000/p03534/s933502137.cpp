#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    string S;  cin >> S;
    int N = S.length();
    vector<int> cnt(3,0);
    for(int i=0; i<N; i++) cnt[S[i]-'a']++;
    sort(cnt.begin(), cnt.end());
    if(cnt[2] - cnt[0] >= 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}
