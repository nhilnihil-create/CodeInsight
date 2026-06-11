#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;

struct Uni {

    vector<int>par;
    vector<int>size;
    Uni(int n)  {
        par.resize(n); size.resize(n, 1);
        for (int i = 0; i < n; i++)par[i] = i;
    }
    

    int root(int x) {
        if (par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    void ch(long long int x, long long int y) {
        int a = root(x);
        int b = root(y);
        if (a == b)return;
      //  if (size[a] < size[b])swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }

};

int main()
{
    int n, m;
    cin >> n >> m;
    Uni t(n + 2);
    vector<long long int>a(m), b(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];

    }
    vector<long long int>ans(m);
    ans[m - 1] =(long long int) n * (n - 1) / 2;

    for (int i = m - 1; i >= 1; i--) {
        ans[i - 1] = ans[i];
     //   cout << t.size[a[i]] << " " << t.size[b[i]] << endl;
        if (t.root(a[i]) != t.root(b[i])) {
            
            ans[i - 1] = ans[i] - (long long int)t.size[t.root(a[i])] * t.size[t.root(b[i])];

            
            t.ch(a[i], b[i]);
        }

    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }


    return 0;

}