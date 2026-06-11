#include<iostream>

using namespace std;
int c[1000];//97
int main()
{
    for(int i=0;i<3;i++){
        scanf("%d",&c[i]);
    }
    if(c[0]==c[1])printf("%d",c[2]);
    else if(c[1]==c[2])printf("%d",c[0]);
    else printf("%d",c[1]);

    return 0;
}
