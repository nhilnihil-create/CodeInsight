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
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define MOD 1000000007
using namespace std;

long value[100005];

int main(int argc, char* argv[])
{
    long k;
    scanf("%ld", &k);
    
    long i;
    for(i=0; i<k; i++) {
        value[i] = -1;
    }

    deque<long> a;
    a.push_back(1);
    value[1]=1;

    while( !a.empty() ) {
        long curr = a.front();
        a.pop_front();
        
        if(curr==0) {
            printf("%ld\n", value[curr]);
            return 0;
        }

        long next0 = (curr*10)%k;
        if(value[next0]<0 || value[next0]>value[curr]) {
            value[next0] = value[curr];
            a.push_front( next0 );
        }

        long next1 = (curr+1)%k;
        if(value[next1]<0) {
            value[next1] = value[curr] + 1;
            a.push_back( next1 );
        }
    }

    return 0;
}
