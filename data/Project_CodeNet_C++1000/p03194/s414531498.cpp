#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    long long n, p;
    scanf("%lld %lld",&n, &p);

    if(n==1) {
        printf("%lld\n", p);
        return 0;
    }

    long long a = 1;

    long flag[10000] = {0};
    flag[0] = flag[1] = 1;
    long i, j;
    for(i=2; i<5000; i++) {
        long tmp = i*2;
        while( tmp < 10000 ) {
            flag[tmp] = 1;
            tmp += i;
        }
    }

    for(i=0; i<10000; i++) {
        if( flag[i] ) {
            continue;
        }
        if ( n < flag[i] ) {
            break;
        }

        long count= 0;
        while( 1 ) {
            if( p % i == 0 ) {
                count ++;
                p = p / i;
            }
            else {
                break;
            }
        }
        long count2 = count / n;
        long k;
        for(k=0; k<count2; k++) {
            a = a * i;
        }
    }

    if ( p > 1 && n==2 ) {
        double s = sqrt((double)p);

        long long b = (long long)s;

        if (b * b == p ) {
            a = a * b;
        }
    }

    //printf("%d\n", p);
    printf("%d\n", a);

	return 0;
}