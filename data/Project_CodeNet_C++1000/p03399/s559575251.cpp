#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    int min1=min(A,B);
    int min2=min(C,D);
    cout<<min1+min2;
    return 0;
}