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
vector<int>a;
int root(int c){
    int x = a[c];
    if (x == c)return x;
    return a[c] = root(a[c]);
    
}
void u(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)return;
    if (y > x)swap(y,x);
    a[x] = y;
}


int main()
{
    int n, m;
    cin >> n >> m;
    a.resize(n + 3);
    vector<int>t(n + 3);// , a(n + 3);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        a[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        int x, y;
        x = root(a[c]); y = root(a[d]);
        //if (c > d)swap(c, d);
        if (x == y)continue;
        u(c, d);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = root(a[i]);
    }
    for(int i=1;i<=n;i++){
        if (a[t[i]] == a[i])ans++;
      //  cout << a[i] <<" "<<a[t[i]]<< " " << ans << endl;;
    }
    cout << ans << endl;
    


    return 0;

}