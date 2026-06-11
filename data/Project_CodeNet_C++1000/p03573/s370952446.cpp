#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm> 
#include <cassert>
#include <string>
//#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, M = 1e7, OO = 0x3f3f3f3f, eps = 0.001;
#define IO() assert(freopen("in.in", "rt", stdin)), assert(freopen("out.out", "wt", stdout))
#define ll long long int
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
void printar(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// template <typename... T>
// void debug(T &... args)
// {
//     ((cerr << args << " "), ...);
//     cerr << endl;
// } 
// struct COMPARE { 
//   bool operator()(pair<string,ll> const& P1, pair<string,ll> const& P2) 
//     { 
        
//         return P1.first < P2.second;
//     }  
// };
// priority_queue<pair<string,ll>,vector<pair<string,ll>>,COMPARE >pq;
int s(int n){
    int x;
    int x1 = 0, x2 = 0, x3 = 0;
    while(n)
    {
        x = n % 10;
        n /= 10;
        if(!(x == 3 || x == 4 || x ==  7)){
            return 0;
        }
        if(x == 3) x1++;
        if(x == 4) x2++;
        if(x == 7) x3++;
    }
    if(x1 && x2 && x3) return 1;
}

int ss(char c1, char c2, char c3){
    int x = 0;
    x += c1 - '0';
    x *= 10;
    x += c2 - '0';
    x *= 10;
    x += c3 - '0';
    return abs(x - 753);
}
int main()
{     
    // icpctraining
    // IO();
    FastIO();
    int a, b, c; cin >> a >> b >> c;
    if(a != b && a != c) cout << a;
    else if(b != a && b != c) cout << b;
    else if(c != a && c != b) cout << c;
    return 0;
    
}