#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int a,b;

    scanf("%d %d", &a, &b);

    int c = a - b;
    int largest = max((a + b), (a * b));
    largest = max(largest, c);

    printf("%d\n", largest);
    return 0;
}