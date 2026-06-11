#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=2001;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
int main()
{
    std::ios::sync_with_stdio(false);
    int n,sum=0;
    cin>>n;
    bitset<N*N> bi;
    bi[0]=1;
    for(int i=1;i<=n;i++)
    {
        /* Make sum=all input [ a1,a2,,,,aN]...  S^2N−1=sum. Now, set{ a1,sum-a1} , {  a2,sum-a2} ,,,,,,
        . let Xi be { a1,a2,..aN } and the remaining numbers (sum-a1 or sum-a2 or.  ...) are recorded as Yi; And make P=min (Xi,Yi), Q=max (Xi,Yi); available: P≤q,p+q=s2n−1=sum,
        from which P≤12sum,q≥12sum is introduced and can be P∈{S1,S2,⋯,S2N−1−1},Q∈{S2N−1,⋯,
        also min( of Xi's) and max(Yi's) difference is constant (for any arbitrary i/o) , it is the median /answer here .....
        */
        int c;
        cin>>c;
        sum+=c;

        /*cout<<" bef : "<<bi<<" | "<<(bi<<c)<<" -- ";/*here are 3 digits: "1 3 2", now to the ' 2 ' number,
        the front ' 1 ', ' 3 ' can be composed and has {0, 1, 3, 4}; So Bitset is now in a state of "11011"
        (the rightmost is No. 0), and if you do not use the number ' 2 ', the state is still "11011"; if the
        number of ' 2 ' is used, the status is "1101100" (i.e., previously available and all +2), and finally
        the two States or (∣) are put up , You get the new state "11111111" (that is, the 0~6 can be made up).*//*
        https://blog.csdn.net/XzzF1024/article/details/79181725 */
        bi|=bi<<c;
        ////cout<<bi<<endl;
    }
    if(n==1) return cout<<sum,0;
    for(int i=(sum+1)/2;i<=sum;i++)
    {
        if(bi[i])
        {
            cout<<i<<endl; 
return 0;
        }
    }

}
