#include <iostream>
using namespace std;
int n;
int a,b;
int main()
{
    scanf("%d",&n);
    if(n==1){printf("Hello World");}
    else{
        scanf("%d%d",&a,&b);
        printf("%d",a+b);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
