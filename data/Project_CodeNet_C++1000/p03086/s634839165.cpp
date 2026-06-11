#include <bits/stdc++.h>
using namespace std;

int main()
{
//    string  n;
//    int cot=0;
//    cin>>n;
//    for(int j=0; j<n.size()-1; j++)
//    {
//        if(n[j] == 'A' || n[j]== 'C' || n[j] =='G' || n[j] =='T')
//        {
//            cot++;
//        }
////        else if(n =="--X" || n=="X--")
////        {
////            flag++;
////        }
//    }
//    cout<<cot<<endl;
//    return 0;
//}
string S;
cin>>S;
int count=0;
int ans=0;
for(int i=0; i<=(int)S.length()-1; i++)
{

    if(S[i]=='A'||S[i]=='T'||S[i]=='C'||S[i]=='G')
    {

        count++;
    }
    else
    {

        if(count>ans)ans=count;
        count=0;
    }
}
if(ans<count)ans=count;
cout<<ans;
return 0;
}
