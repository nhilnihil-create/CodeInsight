#include <iostream>
using namespace std;

int main()
{
    int A;
    int N[4];
    cin >> A;
    int n1 = A /100;
    int n2 = A %100;
    if ((n1<=12 && n1>0) && (n2<=12 && n2>0))
        cout<<"AMBIGUOUS"<<endl;
    else if ((n1<=12 && n1>0))
        cout<<"MMYY"<<endl;
    else if((n2<=12 && n2>0))
        cout<<"YYMM"<<endl;
    else
        cout<<"NA"<<endl;
    return 0;
}
