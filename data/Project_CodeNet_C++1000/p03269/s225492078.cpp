#include <bits/stdc++.h>
using namespace std;

struct E{ int s, e, x; };

int n, c = 1;
vector<E> r;

void g(int s, int e, int x){
    r.push_back({s, e, x});
}

void f(int x){
    if(x == 1) return;
    f(x >> 1);
    c++;
    g(c - 1, c, 0);
    g(c - 1, c, x >> 1);
    if(x & 1) g(1, c, x - 1); 
}

int main(){
    scanf("%d", &n);
    f(n);
    printf("%d %d\n", c, r.size());
    for(E i : r) printf("%d %d %d\n", i.s, i.e, i.x);
}