#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>

using namespace std;
using ll = long long;

int main(){ 
        int x,y;
        cin >> x >> y;
        if((x+1)/2>=y)  cout << "YES";
        else cout << "NO";
        return 0;
}