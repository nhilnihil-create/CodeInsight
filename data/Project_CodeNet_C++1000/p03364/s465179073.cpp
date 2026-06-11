#include<cstdio>

char s[500][500];
char t[500][500];

int main(void) {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s", s[i]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char a = 1;
            for(int k=0; k<n; k++)
                if(s[i][(n+k+j-i)%n] != s[k][j])
                    a = 0;
            if(a) 
                t[i][j] = 1;
            //printf("%d ", t[i][j]);
        }
        //printf("\n");
    }

    int r = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            char a = 1;
            for(int k=0; k<n; k++)
                if(!t[(i+k)%n][(j+k)%n]) a = 0;

            if(a)
                r ++;
        }

    printf("%d\n", r);
}
