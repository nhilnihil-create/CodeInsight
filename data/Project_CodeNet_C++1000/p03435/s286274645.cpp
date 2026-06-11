    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long

        int mat[3][3];
    bool test(int A[],int B[])
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(A[i]+B[j]!=mat[i][j])
                    return 0;
            }
        }
        return 1;
    }
    int main()
    {

        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                cin>>mat[i][j];
        }
        int x=mat[0][0],y=mat[1][1],z=mat[2][2];
        for(int a1=0,b1=x; a1<=x; a1++,b1--)
        {
            for(int a2=0,b2=y; a2<=y; a2++,b2--)
            {
                for(int a3=0,b3=z; a3<=z; a3++,b3--)
                {
                    int A[3],B[3];
                    A[0]=a1;
                    A[1]=a2;
                    A[2]=a3;
                    B[0]=b1;
                    B[1]=b2;
                    B[2]=b3;
                    if(test(A,B))
                    {
                        cout<<"Yes"<<endl;
                        return 0;
                    }

                }
            }
        }
        cout<<"No"<<endl;
        return 0;
    }
