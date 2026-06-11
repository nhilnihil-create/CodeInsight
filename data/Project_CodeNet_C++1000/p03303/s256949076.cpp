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

char str[1005];

int main(int argc, char* argv[])
{
    scanf("%s", str);
    long w;
    scanf("%ld", &w);

    vector<char> z;
    long i;
    for(i=0; i<strlen(str); i+=w) {
        z.push_back(str[i]);
    }
    z.push_back('\0');

    printf("%s\n", &(z[0]));

    return 0;
}
