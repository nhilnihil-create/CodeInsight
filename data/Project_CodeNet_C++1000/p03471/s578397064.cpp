// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    int a=0,b=0,c=0;
    int cnt=0;
    for (int a = 0; a <=n ; a++) {
        for(int b=0;b<=n; b++){
            c=n-a-b;
            if (c>=0 && c<=n && (1000*c==y-10000*a-5000*b)){
                cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;

}