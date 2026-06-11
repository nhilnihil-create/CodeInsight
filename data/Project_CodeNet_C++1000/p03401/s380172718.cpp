#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#include<sstream>
#include<iomanip>
#include <map>
#include <stack>
 
const int64_t cc = pow( 10, 9 );
//std::cout<< std::fixed << std::setprecision(10) << ( double )( max ) / 2;
bool sort_pair( std::pair< std::string, int64_t > origin, std::pair< std::string, int64_t > another )
{
    return origin.second  > another.second;
}
 
int main()
{
    std::string word = "aa";
    int64_t a,b,c,d,e;
    std::cin>> a;
    std::vector< int64_t > list( a );
    b = 0;
    
    for( int i = 0; i < a; i++ )
    {
        std::cin>> list[i];
    }

    std::vector< int64_t > dist;
    dist.push_back( abs( list[0] ) );
    b += abs( list[0] );
    
    for( int i = 1; i < a; i++ )
    {
        b += abs( list[i-1] - list[i] );
        dist.push_back( abs( list[i-1] - list[i] ) );
    }

    b += abs( list.back() );
    dist.push_back( abs( list.back() ) );
    for( int i = 0; i < a; i++ )
    {
        c = b;
        c -= dist[i];
        c -= dist[i+1];
        //std::cout<< dist[i]  << " " << dist[i+1] <<"\n";

        if( i == 0 )
        {
            c += abs( list[i+1] );
        }
        else if( i == a - 1 )
        {
            c += abs( list[i-1] );
        }
        else
        {
            c += abs( list[i-1] - list[i+1] ); 
        }

        std::cout<< c <<"\n";
    }
}
