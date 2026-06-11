#include<bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; i++)
#define DFor(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

int n;
set < pair <int, int> > s;
set < pair <int, int> > :: iterator it; 
int main()
{
    scanf ("%d", &n);
    For (i, 1, n) For (j, i + 1, n) s.insert(make_pair(i, j));
    
    For (i, 1, n / 2) s.erase(s.find(make_pair(i, n - i + (n % 2 == 0))));
    
    printf ("%d\n", s.size());
    for (it = s.begin(); it != s.end(); it++) printf ("%d %d\n", it -> first, it -> second);
    return 0;
}