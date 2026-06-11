#include <iostream> // std::cin
#include <string> // std::string
#include <cstdio> // puts

std::string S;

inline bool check1()
{
    return S[0]=='A';
}

inline bool check2()
{
    int cnt=0;
    int len = S.length();
    for (int i=2;i<=len-2;++i)
    {
        if (S[i]=='C')  ++ cnt;
    }
    return cnt == 1;
}

inline bool check3()
{
   for (int i=0;i<S.length();++i)
   {
        if (S[i]>'A'&&S[i]<='Z'&&S[i]!='C')
            return false;
   }
   return true;
}

inline bool check_tot()
{
    return check1()&&check2()&&check3();
}
int main()
{
    std::cin>>S;
    check_tot()?puts("AC"):puts("WA");
}
