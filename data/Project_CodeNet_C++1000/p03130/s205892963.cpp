/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */

// Author : Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;


#define       TESTCASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define       _input(V3C)  for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define  CH3K(I7, E4, S7)  (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define for4(I7,S4,E4,S7)  for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))




void solveEachTest(lld T35TC453N = 1) {
    
    vector<int> arr(4);
    for4(i, 0, 3, 1) {
        int a, b; cin >> a >> b;
        arr[a-1]++; arr[b-1]++;
    }
    // vector<bool> visited(4, false);
    // int st = 0;
    // visited[st] = true;
    // while (true) {
    //     int nx = arr[st];
    //     if (visited[nx] == true) break;
    //     visited[nx] = true;
    // }

    // for (auto i : visited) {
    //     if (!i) {
    //         cout << "NO\n";
    //         return;
    //     }
    // }

    for (auto i : arr) {
        if (i > 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n"; 

    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought : ok   