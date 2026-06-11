#include<string>
using namespace std;
#include <iostream>

int main()
{
    int s1,s2,s3;
      int a;
    cin>>a;
    s1=a/100%10;
    s2=a/10%10;
    s3=a/1%10;
    std::cout << s1+s2+s3 << std::endl;
    
}
