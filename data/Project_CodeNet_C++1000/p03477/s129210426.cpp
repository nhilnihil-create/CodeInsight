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


int main()
{     
    //IO();
    FastIO();
    int a, b, c, d; cin >> a >> b >> c >> d;
    if((a+b) > (c+d)) cout << "Left";
    else if((a+b) < (c+d)) cout << "Right";
    else cout << "Balanced";
    return 0;
    
}