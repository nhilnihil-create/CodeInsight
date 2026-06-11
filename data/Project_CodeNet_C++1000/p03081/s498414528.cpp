#include <fstream>
#include <iostream>
#define nmax 200001

using namespace std;
/*ifstream fin("p.in");
ofstream fout("p.out");
*/
int n,q;
char s[nmax];

struct query
{
    char pos;
    char dir;
};
query vec_q[nmax];

int verif(int val)
{
    char square=s[val-1];
    //fout<<square<<" ";
    for(int i=1; i<=q; i++)
        {
            //fout<<vec_q[i].pos<<" "<<square<<"\n";
            if(vec_q[i].pos==square)
                {
                    //fout<<square<<" ";
                    if(vec_q[i].dir=='L') val--;
                    else val++;
                    if(val>n) return -1;
                    else if(val<1) return -2;
                    square=s[val-1];
                }
        }
    //fout<<"\n check \n";
    return 1;
}

int best_left_out_right()
{
    int st=1;
    int dr=n;
    int sol;
    int pp=0;
    while(st<=dr)
        {
            //fout<<"st="<<st<<" dr="<<dr<<" ";
            int mij=(st+dr)/2;
            //fout<<mij<<" ";
            if(verif(mij)==1 || verif(mij)==-2)
                st=mij+1;
            else if(verif(mij)==-1) {pp=1; sol=mij; dr=mij-1;}
            //fout<<"\n";
        }
    if(!pp) return n+1;
    return sol;
}

int best_right_out_left()
{
    int st=1;
    int dr=n;
    int sol;
    int pp=0;
    while(st<=dr)
        {
            //fout<<"st="<<st<<" dr="<<dr<<" ";
            int mij=(st+dr)/2;
            //fout<<mij<<" ";
            if(verif(mij)==1 || verif(mij)==-1)
                {
                    dr=mij-1;
                }
            else if(verif(mij)==-2) {pp=1;st=mij+1; sol=mij;}
            //fout<<"\n";
        }
    if(!pp) return 0;
    return sol;
}

int main()
{
    cin>>n>>q;
    cin>>s;
    for(int i=1; i<=q; i++)
        {
            cin>>vec_q[i].pos>>vec_q[i].dir;
        }

    int val_1=best_left_out_right();
    //fout<<"\n next\n";
    int val_2=best_right_out_left();
    //fout<<"\n"<<val_1<<" "<<val_2<<" ";
    cout<<n-val_2-(n-val_1+1);
    return 0;
}
