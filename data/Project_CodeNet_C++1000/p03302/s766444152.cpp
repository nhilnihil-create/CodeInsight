#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;

int main(int argc, char* argv[])
{
    long a, b;
    scanf("%ld%ld", &a, &b);
    if(a+b==15) {
        printf("+\n");
    }
    else if (a*b==15) {
        printf("*\n");
    }
    else {
        printf("x\n");
    }

    return 0;
}
