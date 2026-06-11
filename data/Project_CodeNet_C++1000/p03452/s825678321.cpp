#include <bits/stdc++.h>

using namespace std;

const int N = 100005 ;

int noPeople , noMuc ;


vector < pair< int , int > > allMuc [ N ];
int viz [ N ] ;
int dist [ N ] ;
int spy ;

void dfs ( int crNode ){

    viz[ crNode ] = 1 ;

    for ( pair < int , int > crPair : allMuc[ crNode ] ){
        int vec = crPair.first ;
        int cost = crPair.second ;
        if ( viz [ vec ] == 1 ){
            if (dist[ vec ] - dist [ crNode ] != cost ){
                spy = 1 ;
            }

        }else{
            dist [ vec ] = dist [ crNode ] + cost ;
            dfs( vec );
        }

    }

}

int main()
{


    scanf("%d%d",&noPeople,&noMuc);

    for ( int i = 0 ; i < noMuc ; i++ ){
        int x , y , cost ;
        scanf("%d%d%d",&x,&y,&cost);
        allMuc [ x ].push_back ( make_pair( y , cost ) );
        allMuc [ y ].push_back ( make_pair( x , -cost ) );
    }


    for ( int i = 1 ; i <= noPeople ; i++ ){
        if ( viz [ i ] ==0  ){
            dfs ( i );
        }
    }

    if ( spy == 0 ){
        printf("Yes");
        return 0 ;
    }
    printf("No");


    return 0;
}
