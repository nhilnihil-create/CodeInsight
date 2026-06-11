#include <bits/stdc++.h>


using namespace std;

const int N = 200010;

int noNodes , noMuchii ;
char val[ N ];
int gradA[ N ] , gradB [ N ]  , viz [ N ] ;
vector < int  > allMuc [ N ] ;
queue < int > que ;


int main(){


    scanf("%d%d",&noNodes , &noMuchii);

    scanf("%s",val + 1);

    for ( int i = 0 ; i < noMuchii ; i++ ){
        int x , y ;
        scanf("%d %d",&x,&y);
        allMuc [ x ].push_back( y );
        allMuc [ y ].push_back( x );
        if ( val [ x ] == 'A'){
            gradA [ y ] ++ ;
        }else{
            gradB [ y ] ++ ;
        }
        if ( val [ y ] == 'A'){
            gradA [ x ] ++ ;
        }else{
            gradB [ x ] ++ ;
        }
    }

    for ( int i = 1 ; i <= noNodes ; i++ ){
        if ( !gradA [ i ] || !gradB [ i ] ){
            que.push( i ) ;
            viz [ i ] = 1 ;
        }
    }

    while ( !que.empty() ){
        int crNode = que.front();
        que.pop();

//        if ( crNode == 13 ){
//            printf("ohahalera");
//        }

        for ( int vec : allMuc [ crNode ]){
            if ( viz [ vec ] ){
                continue ;
            }

            if ( val [ crNode ] == 'A'){
                gradA [ vec ]-- ;
            }else{
                gradB [ vec ]-- ;
            }
            if ( !gradA [ vec ] || !gradB [ vec ] ){
                viz [ vec ] = 1 ;
                que.push( vec );
            }

        }

    }

    for ( int i = 1 ; i <= noNodes ; i++ ){
        if ( viz [ i ] == 0 ){
            printf("Yes");
            return 0 ;
        }
    }
    printf("No");
    return 0;
}
