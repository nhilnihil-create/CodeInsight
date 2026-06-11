#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#pragma warning(disable:4996)

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define MOD 1000000007
using namespace std;

int main(int argc, char* argv[])
{
    long a,b;
    scanf("%ld %ld", &a, &b);

    long na=(a-2+50)/50;
    if(a==1) na=1;
    long nb=(b-2+50)/50;
    if(b==1) nb=1;

    printf("%ld %ld\n", (na+nb)*2, 100);

    long i,j;
    if(a==1) {
        for(i=0; i<2; i++) {
            for(j=0; j<100; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
    else {
        for(i=0; i<na; i++) {
            long k = (i==na-1? (a-2)%50+1: 50); 
            for(j=0; j<k; j++) {
                printf(".#");
            }
            for(j=0; j<50-k; j++) {
                printf("##");
            }
            printf("\n");

            for(j=0; j<100; j++) {
                printf("#");
            }
            printf("\n");
        }
    }

    if(b==1) {
        for(i=0; i<2; i++) {
            for(j=0; j<100; j++) {
                printf(".");
            }
            printf("\n");
        }
    }
    else {
        for(i=0; i<nb; i++) {
            for(j=0; j<100; j++) {
                printf(".");
            }
            printf("\n");

            long k = (i==nb-1? (b-2)%50+1: 50); 
            for(j=0; j<k; j++) {
                printf("#.");
            }
            for(j=0; j<50-k; j++) {
                printf("..");
            }
            printf("\n");
        }
    }

    return 0;
}
