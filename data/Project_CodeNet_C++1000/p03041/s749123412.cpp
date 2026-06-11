#include <iostream>

using namespace std;


int main()
{
    char in[55];
int a,b;scanf("%d%d",&a,&b);
scanf("%s",in);
in[b-1]+=32;

printf("%s\n",in);


    return 0;
}
