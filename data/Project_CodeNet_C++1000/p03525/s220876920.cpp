#include <stdio.h>
#include <algorithm>
#include <vector>
#define MIN(a, b) ((a)>(b)? (b): (a))
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    for(i=0; i<n; i+=2) {
        a[i]=24-a[i];
    }
    sort(a.begin(), a.end());

    int min=MIN(a[0], 24-a[n-1]);
    for(i=1; i<n; i++) {
        min=MIN(min,a[i]-a[i-1]);
    }
    printf("%d\n", min);

    return 0;
}