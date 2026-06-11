#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int a,b; cin >> a >> b;
    puts(a*b%2==0?"Even":"Odd");
    return 0;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/