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

vector<long long int>t;
int n;
long long int ans;
void R(vector<long long int>a) {
    if (a.size() >= n) {
        int d = 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] % 2 == 0) {
                d = 0;
            }
                
        //    cout << a[i] << " ";
            
            
        } if (!d)ans++;
      //  cout<<d <<" "<<ans<< endl;
       
        return;

    }int i = a.size();
    
    a.push_back(t[i]); R(a);
    a[i] = t[i] - 1; R(a);
    a[i] = t[i ]+ 1; R(a);

}

int main()
{

    cin >> n;
    vector<long long int>a(n),b;
    t = a;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    ans = 0;
    R(b);
    cout << ans << endl;


    return 0;

}