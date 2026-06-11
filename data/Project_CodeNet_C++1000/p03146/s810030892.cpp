#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    int a=1;
    cin>>n;

    while(true)
    {
        if(n == 4 || n == 2 || n == 1)
        {
            cout << a+3 << endl;
            break;
        }
        if(n%2)
        {
            n = 3*n + 1;
        }
        else {
            n /= 2;
        }
        a++;
  }
}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//    int n;
//    vector<int>a(1000001);
//    cin>>n;
//
//    a.at(n)++;
//
//    for(int i=2; ; i++)
//    {
//        if(n%2)
//        {
//            n = 3*n + 1;
//        }
//        else {
//            n /= 2;
//        }
//
//    if(a.at(n)++)
//    {
//        cout << i << endl;
//        return 0;
//    }
//  }
//}
