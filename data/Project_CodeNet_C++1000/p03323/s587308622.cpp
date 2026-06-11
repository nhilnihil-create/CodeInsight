#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


typedef long long int ll;
typedef unsigned long long  ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef deque <int> di;
typedef deque <char> dc;

#define f(i, a, b) for (int i = a; i < b; i++)
#define f2(i, a, b) for (int i = a; i <=b; i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front;
int main() {
int a, b;
cin >> a >> b;
if (a > 8 || b > 8) {
    cout << ":(";
}
else {
    cout << "Yay!";
}
return 0;
}
